//      houmen.c ����

inherit ROOM;

void create()
{
        set("short","����");
        set("long",@LONG
����ѩɽ�µĺ��š�һƬ���������ģ�������������Ҳ�㣬����
Ҳ�����Ǻ��ţ���Ȼδ�⺮�ᣬ��Ҳ�ܿ���Ҵ�š�
LONG );
	set("outdoors", "xueshansi");
        set("exits",([
            "south" : __DIR__"houyuan",
        ]));
        set("no_clean_up", 0);
	set("coor/x", -70050);
	set("coor/y", -19880);
	set("coor/z", 120);
	setup();
        replace_program(ROOM);
}
