export let mynav = {
    template: '<div><div class="nav"><h5>{{title}}</h5></div>' +
        '<div class="leftBar">' +
        '<ul>' +
        '<li>1</li>' +
        '<li>2</li>' +
        '</ul>' +
        '</div>' +
        '<div class="content">' +
        '<slot name="content"></slot>' +
        '</div>' +
        '</div>',
    props: {
        title: {
            type: String,
            default: 'Title'
        }
    }
};
