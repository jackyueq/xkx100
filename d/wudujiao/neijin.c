// Room: /d/wudujiao/neijin.c

inherit ROOM;

void create()
{
        set("short", "�ͷ�");
        set("long", @LONG
������һ��ͷ�����ǽ����һ��ͨ�̣������ۿ�����������
����Ϣ�����߰���һ���������õ�ľ����һ���η�������������
�ߺȲ衣
LONG
        );

        set("exits", ([
                "east" : __DIR__"xiaodian",
        ]));
        set("objects", ([
                CLASS_D("wudujiao")+"/daoshi": 1,
        ]));

	set("coor/x", -45020);
	set("coor/y", -79000);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}