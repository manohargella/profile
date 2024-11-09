document.addEventListener('DOMContentLoaded', () => {
    const grid = document.querySelector('.grid');

    // Array to hold multiple link groups for dynamic creation
    const linkGroups = [
        { title: 'Fuck list', links: ['Link One', 'Link Two', 'Link Three', 'Link Four', 'Link Five'] },
        { title: 'Category Title', links: ['Link One', 'Link Two', 'Link Three', 'Link Four', 'Link Five'] },
        { title: 'Category Title', links: ['Link One', 'Link Two', 'Link Three', 'Link Four', 'Link Five'] },
        // Add more groups as needed
    ];

    linkGroups.forEach(group => {
        const box = document.createElement('div');
        box.classList.add('box');

        const title = document.createElement('h2');
        title.textContent = group.title;
        box.appendChild(title);

        const ul = document.createElement('ul');
        group.links.forEach(linkText => {
            const li = document.createElement('li');
            const a = document.createElement('a');
            a.href = '#';
            a.textContent = linkText;
            li.appendChild(a);
            ul.appendChild(li);
        });
        box.appendChild(ul);

        grid.appendChild(box);
    });
});