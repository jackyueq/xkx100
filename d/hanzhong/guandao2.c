// guandao2.c �ٵ�
// Winder Oct.10 1998

inherit ROOM;

void create()
{
        set("short", "�ٵ�");
        set("long", @LONG
����һ���ٸ��޽��Ĵ����������Լ���Կ����书��Ķ��š�
Զ��������Կ���Ρ��ĳ�ǽ��������ͨ����ԭ��·���������
���ƺ�����һ�֡�Ȱ������һ���ƣ����������޹��ˡ��ĸо���
LONG
        );
        set("outdoors", "hanzhong");
        set("exits", ([
                "east" : __DIR__"guandao1",
                "west" : __DIR__"dongmen",
        ]));
        set("no_clean_up", 0);
	set("coor/x", -3110);
	set("coor/y", -10);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}