//      tiantai.c ��̨

inherit ROOM;

void create()
{
        set("short","��̨");
        set("long",@LONG
������ѩɽ�µĸߴ������߿ɼ���ΰ�Ĵ�ѩɽ���ϱ߿��Ը������
�羵��ʥ����
LONG );
	set("outdoors", "xueshansi");
        set("exits",([
                "west" : __DIR__"neidian",
        ]));
        set("no_clean_up", 0);
	set("coor/x", -69990);
	set("coor/y", -19880);
	set("coor/z", 140);
	setup();
        replace_program(ROOM);
}
