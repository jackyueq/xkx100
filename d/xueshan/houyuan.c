//      houyuan.c ��Ժ

inherit ROOM;

void create()
{
        set("short","��Ժ");
        set("long",@LONG
������ѩɽ�µĺ�Ժ����Ժ�������˼������ѩ�ɣ��ڰ׻λε�
ѩɽ�����£�����ƮȻ�������Ķ����ϱ������䳡�������Ǻ��š�
LONG );
        set("outdoors","xueshansi");
        set("exits",([
                "eastdown" : __DIR__"dilao",
                "north" : __DIR__"houmen",
                "south" : __DIR__"chang",
        ]));
        set("no_clean_up", 0);
	set("coor/x", -70050);
	set("coor/y", -19890);
	set("coor/z", 120);
	setup();
        replace_program(ROOM);
}
