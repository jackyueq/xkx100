// xiaocun.c С��ׯ
// Winder Oct.10 1998

inherit ROOM;

void create()
{
        set("short", "С��ׯ");
        set("long", @LONG
����һƬС��ׯ��������һ��Сɽ�������ľ����Ƕ����ٵ�
����ȥ����Ȼ���书�򲻹����塢�����ɽ·��������Ը�������и�
Ů��֯���ճ����������Ъ���ϴ�ͳ��������Ȼ��ƶ��ȴ������ң��
LONG
        );
        set("outdoors", "hanzhong");
        set("exits", ([
                "northwest" : __DIR__"guchang",
                "southdown" : __DIR__"shanlu",
        ]));
        set("no_clean_up", 0);
	set("coor/x", -3160);
	set("coor/y", 10);
	set("coor/z", 10);
	setup();
        replace_program(ROOM);
}
