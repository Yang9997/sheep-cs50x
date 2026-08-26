/*
    ================================
    网站数据
    ================================

    我们先把所有栏目需要显示的内容
    集中保存起来。

    以后你真正填写内容时，
    主要修改这里即可。
*/

const sections = {

    courses: {
        title: "课程",

        description:
            "这里是课程部分的整体介绍。下面列出了目前的十个课程位置。点击左侧导航栏，或者点击正文中的课程名称，都可以进入对应课程的详细介绍。",

        items: [
            {
                title: "CS50",
                description:
                    "这里是 CS50 的具体介绍。你以后可以把课程简介、学习笔记、课程链接、完成情况等内容放在这里。",
                github:
                    "https://github.com/Yang9997/sheep-cs50x"
            },

            {
                title: "课程 2",
                description:
                    "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx。"
            },

            {
                title: "课程 3",
                description:
                    "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx。"
            },

            {
                title: "课程 4",
                description:
                    "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx。"
            },

            {
                title: "课程 5",
                description:
                    "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx。"
            },

            {
                title: "课程 6",
                description:
                    "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx。"
            },

            {
                title: "课程 7",
                description:
                    "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx。"
            },

            {
                title: "课程 8",
                description:
                    "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx。"
            },

            {
                title: "课程 9",
                description:
                    "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx。"
            },

            {
                title: "课程 10",
                description:
                    "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx。"
            }
        ]
    },


    labs: {
        title: "实验",

        description:
            "这里是实验部分的整体介绍。以后可以放课程实验、独立练习或者其他实践内容。",

        items: [
            {
                title: "实验 1",
                description: "这里是实验 1 的具体内容。"
            },
            {
                title: "实验 2",
                description: "这里是实验 2 的具体内容。"
            },
            {
                title: "实验 3",
                description: "这里是实验 3 的具体内容。"
            },
            {
                title: "实验 4",
                description: "这里是实验 4 的具体内容。"
            },
            {
                title: "实验 5",
                description: "这里是实验 5 的具体内容。"
            },
            {
                title: "实验 6",
                description: "这里是实验 6 的具体内容。"
            },
            {
                title: "实验 7",
                description: "这里是实验 7 的具体内容。"
            },
            {
                title: "实验 8",
                description: "这里是实验 8 的具体内容。"
            },
            {
                title: "实验 9",
                description: "这里是实验 9 的具体内容。"
            },
            {
                title: "实验 10",
                description: "这里是实验 10 的具体内容。"
            }
        ]
    },


    projects: {
        title: "项目",

        description:
            "这里是项目部分的整体介绍。以后可以放你完成的程序、网站、课程 Final Project 或其他个人项目。",

        items: [
            {
                title: "项目 1",
                description: "这里是项目 1 的具体介绍。"
            },
            {
                title: "项目 2",
                description: "这里是项目 2 的具体介绍。"
            },
            {
                title: "项目 3",
                description: "这里是项目 3 的具体介绍。"
            },
            {
                title: "项目 4",
                description: "这里是项目 4 的具体介绍。"
            },
            {
                title: "项目 5",
                description: "这里是项目 5 的具体介绍。"
            },
            {
                title: "项目 6",
                description: "这里是项目 6 的具体介绍。"
            },
            {
                title: "项目 7",
                description: "这里是项目 7 的具体介绍。"
            },
            {
                title: "项目 8",
                description: "这里是项目 8 的具体介绍。"
            },
            {
                title: "项目 9",
                description: "这里是项目 9 的具体介绍。"
            },
            {
                title: "项目 10",
                description: "这里是项目 10 的具体介绍。"
            }
        ]
    },


    about: {
        title: "关于我",

        description:
            "这里是关于我的部分。你可以在这里写个人介绍、学习方向、兴趣、联系方式或者其他希望展示的信息。",

        items: null
    },


    reward: {
        title: "奖励时间！",

        description:
            "这里是奖励时间！你可以把它做成一个比较自由的区域，例如收藏、动画、小游戏、喜欢的角色、音乐或者其他内容。",

        items: null
    }

};


/*
    ================================
    找到页面上的 HTML 元素
    ================================
*/

const topButtons =
    document.querySelectorAll(".nav-button");

const sideNav =
    document.querySelector("#sideNav");

const sideList =
    document.querySelector("#sideList");

const mainContent =
    document.querySelector("#mainContent");


/*
    当前正在显示哪个一级栏目。

    默认进入课程。
*/
let currentSection = "courses";


/*
    当前选择了哪个侧栏项目。

    null 表示目前正在看栏目总览，
    没有选择具体课程/实验/项目。
*/
let currentItemIndex = null;


/*
    ================================
    生成侧边栏
    ================================
*/

function renderSideNav(sectionName)
{
    const section = sections[sectionName];

    /*
        先把之前的侧栏清空。
    */
    sideList.innerHTML = "";


    /*
        如果这个栏目没有 items，
        就不需要侧栏。
    */
    if (!section.items)
    {
        return;
    }


    /*
        遍历这个栏目中的 10 个项目。
    */
    section.items.forEach(function(item, index)
    {
        /*
            创建 li
        */
        const li = document.createElement("li");


        /*
            创建 button
        */
        const button =
            document.createElement("button");


        button.type = "button";

        button.className =
            "btn side-button";


        /*
            保存这个按钮对应的是第几个项目。
        */
        button.dataset.index = index;


        /*
            如果当前正好选择了这个项目，
            给它 selected。
        */
        if (currentItemIndex === index)
        {
            button.classList.add("selected");
        }


        /*
            创建按钮里面的文字 span。
        */
        const text =
            document.createElement("span");


        text.className =
            "side-text";


        text.textContent =
            item.title;


        /*
            span 放进 button。
        */
        button.appendChild(text);


        /*
            button 放进 li。
        */
        li.appendChild(button);


        /*
            li 放进 ul。
        */
        sideList.appendChild(li);
    });
}


/*
    ================================
    显示栏目总览
    ================================
*/

function renderOverview(sectionName)
{
    const section = sections[sectionName];


    let html = `
        <article>

            <h1 class="main-title">
                ${section.title}
            </h1>

            <p>
                ${section.description}
            </p>
    `;


    /*
        如果这个栏目有侧栏项目，
        就在正文中生成对应链接。
    */
    if (section.items)
    {
        html += `
            <h2 class="content-title">
                内容列表
            </h2>

            <ol class="content-list">
        `;


        section.items.forEach(
            function(item, index)
            {
                html += `
                    <li>

                        <button
                            class="content-link"
                            data-index="${index}"
                            type="button"
                        >
                            ${item.title}
                        </button>

                        —— xxxxxxxxxxxxxxxxxxxx
                `;


                /*
                    如果这个项目存在 github 数据，
                    就额外生成 GitHub 链接。

                    目前只有 CS50 有 github，
                    所以其他课程不会显示。
                */
                if (item.github)
                {
                    html += `
                        <a
                            class="github-link"
                            href="${item.github}"
                            target="_blank"
                            rel="noopener noreferrer"
                        >
                            GitHub
                        </a>
                    `;
                }


                html += `
                    </li>
                `;
            }
        );


        html += `
            </ol>
        `;
    }


    html += `
        </article>
    `;


    mainContent.innerHTML = html;
}


/*
    ================================
    显示具体课程 / 实验 / 项目
    ================================
*/

function renderItem(sectionName, index)
{
    const section = sections[sectionName];

    const item = section.items[index];


    mainContent.innerHTML = `
        <article>

            <h1 class="main-title">
                ${item.title}
            </h1>

            <p>
                ${item.description}
            </p>


            <h2 class="content-title">
                详细内容
            </h2>

            <p>
                xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
                xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
                xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
            </p>

            <p>
                xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
                xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
            </p>


            <button
                class="content-link"
                id="backToOverview"
                type="button"
            >
                ← 返回${section.title}总览
            </button>

        </article>
    `;
}


/*
    ================================
    更新顶部导航选中状态
    ================================
*/

function updateTopSelection()
{
    topButtons.forEach(function(button)
    {
        /*
            先全部取消 selected。
        */
        button.classList.remove("selected");


        /*
            找到当前栏目对应的按钮。
        */
        if (
            button.dataset.section
            === currentSection
        )
        {
            button.classList.add("selected");
        }
    });
}


/*
    ================================
    更新侧栏选中状态
    ================================
*/

function updateSideSelection()
{
    const sideButtons =
        document.querySelectorAll(".side-button");


    sideButtons.forEach(function(button)
    {
        button.classList.remove("selected");


        const index =
            Number(button.dataset.index);


        if (index === currentItemIndex)
        {
            button.classList.add("selected");
        }
    });
}


/*
    ================================
    侧栏切换动画
    ================================
*/

function changeSidebar(sectionName)
{
    const newSection =
        sections[sectionName];


    /*
        如果旧侧栏现在本来就隐藏，
        不需要先播放离开动画。
    */
    if (
        sideNav.classList.contains(
            "sidebar-hidden"
        )
    )
    {
        /*
            新栏目也没有侧栏。
        */
        if (!newSection.items)
        {
            return;
        }


        /*
            新栏目有侧栏。

            先生成内容。
        */
        renderSideNav(sectionName);


        /*
            取消隐藏。
        */
        sideNav.classList.remove(
            "sidebar-hidden"
        );


        /*
            先把新侧栏瞬间放在屏幕左边。
        */
        sideNav.classList.add(
            "is-entering"
        );


        /*
            强制浏览器确认当前位置。
        */
        void sideNav.offsetWidth;


        /*
            去掉 is-entering 后，
            CSS transition 会让它移动回来。
        */
        sideNav.classList.remove(
            "is-entering"
        );


        return;
    }


    /*
        旧侧栏先向左离开。
    */
    sideNav.classList.add(
        "is-leaving"
    );


    /*
        CSS 动画是 0.32 秒。

        320ms 后说明旧侧栏已经消失。
    */
    setTimeout(function()
    {
        /*
            如果新的栏目没有侧栏，
            直接隐藏。
        */
        if (!newSection.items)
        {
            sideNav.classList.add(
                "sidebar-hidden"
            );

            sideNav.classList.remove(
                "is-leaving"
            );

            return;
        }


        /*
            换成新栏目的侧栏内容。
        */
        renderSideNav(sectionName);


        /*
            删除旧的离开状态。
        */
        sideNav.classList.remove(
            "is-leaving"
        );


        /*
            先把新的侧栏放在屏幕左边。
        */
        sideNav.classList.add(
            "is-entering"
        );


        /*
            强制浏览器处理一次布局。
        */
        void sideNav.offsetWidth;


        /*
            删除 is-entering。

            浏览器会从左边
            动画移动到正常位置。
        */
        sideNav.classList.remove(
            "is-entering"
        );

    }, 320);
}


/*
    ================================
    点击顶部导航
    ================================
*/

topButtons.forEach(function(button)
{
    button.addEventListener(
        "click",
        function()
        {
            const newSection =
                button.dataset.section;


            /*
                如果点击的就是当前栏目：

                不切换侧栏，
                只返回栏目总览。
            */
            if (newSection === currentSection)
            {
                currentItemIndex = null;

                renderOverview(
                    currentSection
                );

                updateSideSelection();

                return;
            }


            /*
                先保存新的栏目。
            */
            currentSection =
                newSection;


            /*
                点击一级栏目后，
                默认进入栏目总览。
            */
            currentItemIndex =
                null;


            /*
                更新顶部加粗状态。
            */
            updateTopSelection();


            /*
                切换主体内容。
            */
            renderOverview(
                currentSection
            );


            /*
                播放侧边栏切换动画。
            */
            changeSidebar(
                currentSection
            );
        }
    );
});


/*
    ================================
    点击侧栏
    ================================

    我们监听整个 ul，
    而不是分别监听十个按钮。
*/

sideList.addEventListener(
    "click",
    function(event)
    {
        /*
            closest 会寻找被点击位置
            最近的 .side-button。
        */
        const button =
            event.target.closest(
                ".side-button"
            );


        /*
            如果点的不是侧栏按钮，
            什么都不做。
        */
        if (!button)
        {
            return;
        }


        const index =
            Number(button.dataset.index);


        currentItemIndex =
            index;


        /*
            显示对应正文。
        */
        renderItem(
            currentSection,
            index
        );


        /*
            更新侧栏加粗状态。
        */
        updateSideSelection();
    }
);


/*
    ================================
    点击主体中的课程/实验/项目链接
    ================================

    因为 mainContent 的 HTML 会不断变化，
    所以直接监听 mainContent 本身。
*/

mainContent.addEventListener(
    "click",
    function(event)
    {
        /*
            是否点击了正文中的项目链接？
        */
        const itemLink =
            event.target.closest(
                ".content-link[data-index]"
            );


        if (itemLink)
        {
            const index =
                Number(
                    itemLink.dataset.index
                );


            currentItemIndex =
                index;


            renderItem(
                currentSection,
                index
            );


            updateSideSelection();


            /*
                回到 panel 上方附近，
                方便阅读刚刚打开的内容。
            */
            window.scrollTo({
                top: 0,
                behavior: "smooth"
            });


            return;
        }


        /*
            是否点击了“返回总览”？
        */
        const backButton =
            event.target.closest(
                "#backToOverview"
            );


        if (backButton)
        {
            currentItemIndex =
                null;


            renderOverview(
                currentSection
            );


            updateSideSelection();
        }
    }
);


/*
    ================================
    页面第一次打开
    ================================
*/

renderSideNav("courses");

renderOverview("courses");

updateTopSelection();
