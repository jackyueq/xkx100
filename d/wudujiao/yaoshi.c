// Room: /d/wudujiao/yaoshi.c

inherit ROOM;
string* objs = ({
        __DIR__"obj/fugu",
        __DIR__"obj/hedinghong",
        __DIR__"obj/chuanxin",
        __DIR__"obj/qianrizui",
        __DIR__"obj/shexinzi",
//      __DIR__"obj/xiang",
        __DIR__"obj/fugu",
        __DIR__"obj/chuanxin",
        __DIR__"obj/shexinzi",
        __DIR__"obj/hedinghong",

});

void create()
{
        set("short", "ҩ��");
        set("long", @LONG
�������嶾�̴��ҩƷ�ĵط���ֻ��ʮ�������ľ��һ���ſ�������
�������ٸ���С���룬ÿ���������涼�������������һ�б�ǩ�������
���Ÿ������ҩ�ģ����д�������ж��ġ��Ա�һ�����Ϸ��ż����ղ���
�Ĳ�ҩ��
LONG
        );

        set("exits", ([
                "west" : __DIR__"nanyuan",
        ]));
        set("objects", ([
                objs[random(sizeof(objs))] : 1,
                objs[random(sizeof(objs))] : 1,
                __DIR__"obj/zhulou"        : 2,
        ]));

	set("coor/x", -44910);
	set("coor/y", -81060);
	set("coor/z", 30);
	setup();
        replace_program(ROOM);
}