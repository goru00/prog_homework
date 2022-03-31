import { PageFlip } from 'page-flip';

document.addEventListener('DOMContentLoaded', function() {
    const pageFlip = new PageFlip(
        document.getElementById("bookWeb"), {
            width: 550,
            height: 733,
            size: "stretch",
            minWidth: 315,
            maxWidth: 1000,
            minHeight: 420,
            maxHeight: 1350,
            maxShadowOpacity: 0.5,
            showCover: true,
            mobileScrollSupport: false
        }
    );

    pageFlip.loadFromHTML(document.querySelectorAll(".page"));

    document.querySelector(".page-total").innerHTML = pageFlip.getPageCount();
    document.querySelector(".page-orientation").innerHTML = pageFlip.getOrientation();

    document.querySelector(".btn-prev").addEventListener('click', () => {
        pageFlip.flipPrev();
    });

    document.querySelector('btn-next').addEventListener('click', () => {
        pageFlip.flipNext();
    });

    pageFlip.on('flip', (e) => {
        document.querySelector('.page-state').innerHTML = e.data;
    });

    pageFlip.on('changeState', (e) => {
        document.querySelector('.page-state').innerHTML = e.data;
    });

    pageFlip.on('changeOrientation', (e) => {
        document.querySelector('.page-orientation').innerHTML = e.data;
    });
});