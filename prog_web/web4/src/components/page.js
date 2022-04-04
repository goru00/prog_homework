import React from 'react';
import '../main.css';

const stylePage1 = {
    backgroundImage: `url("../static/images/bgPage1.png")`
};
const stylePage2 = {
    backgroundImage: `url("../static/images/bgPage1.jpg")`
};

export const Page = React.forwardRef((props, ref) => {
    return (
        <div className='page' ref={ref} style={stylePage1}>
            <div className='page-content'>
                <div className='page-header'>Глава {props.header}</div>
                <div className='page-image'></div>
                <div className='page-text'>{props.children}</div>
                <div className='page-footer'>{props.page}</div>
            </div>
        </div>
    )
});

