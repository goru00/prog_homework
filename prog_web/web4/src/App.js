import HTMLFlipBook from "react-pageflip";
import { Page } from "./components/page";
import config from './components/config';
import './main.css';

function App(props) {
  return (
      <HTMLFlipBook 
        width={config.width}
        height={config.height}
        size={config.size}
        minWidth={config.minWidth}
        maxWidth={config.maxWidth}
        minHeight={config.minHeight}
        maxHeight={config.maxHeight}
        maxShadowOpacity={config.maxShadowOpacity}
        showCover={config.showCover}
        mobileScrollSupport={config.mobileScrollSupport}
      >
        <Page header={1} page={1}>Текст 1</Page>
        <Page header={2} page={2}>Текст 2</Page>
        <Page header={3} page={3}>Текст 3</Page>
        <Page header={4} page={4}>Текст 4</Page>
      </HTMLFlipBook>
  );
}

export default App;
