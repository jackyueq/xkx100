// Room: /u/cuer/emei/yhrkou.c
inherit ROOM;
void create()
{
        set("short", "�ƺ����");
        set("long", @LONG
������Ƕ����������ƺ��ˣ�������ȥ����ɽ��Ұ��
������������Ū�����Լ����ںγ�������������ԼԼ��
һ��С��ͨ��ǰ�������ǻ�ȥ�ɡ�
LONG
        );
        set("exits", ([
            "enter" : __DIR__"hcahoudian",
            "north" : __DIR__"yunhai1",
        ]));
	set("no_clean_up", 0);
	set("coor/x", -6200);
	set("coor/y", -1190);
	set("coor/z", 200);
	setup();
        replace_program(ROOM);
}