// Room: /d/wudujiao/bianzhai3.c

inherit ROOM;

void create()
{
        set("short", "��կ����");
        set("long", @LONG
���������置�ؽ磬ֻ����ɽ��ˮ�㣬�羰����ԭ����ͬ��
����·�ϣ���ʱ������������Ů��·����Ұ���ظ����裬�پ���
���泩����Ը���ϴ��硣������һ����ˮ��סȥ·��
LONG
        );
        set("outdoors", "wudujiao");
	set("no_clean_up", 0);
        set("exits", ([
                "east" : __DIR__"jiang1",
                "northeast" : __DIR__"bianzhai1",
                "north" : __DIR__"bianzhai2",
        ]));

	set("coor/x", -46010);
	set("coor/y", -81010);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}