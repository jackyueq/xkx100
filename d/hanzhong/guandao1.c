// guandao1.c �ٵ�
// Winder Oct.10 1998

inherit ROOM;

void create()
{
        set("short", "�ٵ�");
        set("long", @LONG
����һ�����������ͨ���书�򡣵��ϵ����˺ܶ࣬����ǵ�
��ͷ�Լ����Լ���·����Ȼ������������õõ�����������һ��
������ƥ���������߷ɳ۶�����������һƬ��ɳ��
LONG
        );
        set("outdoors", "hanzhong");
        set("exits", ([
                "west" : __DIR__"guandao2",
                "east" : "/d/changan/road3",
        ]));
        set("no_clean_up", 0);
	set("coor/x", -3100);
	set("coor/y", -10);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}
