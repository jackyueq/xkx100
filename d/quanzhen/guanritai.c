// guanritai.c ����̨
// Winder Oct.10 1998

inherit ROOM;

void create()
{
        set("short", "����̨");
        set("long", @LONG
����������ɽ�ϵĹ���̨����֪�ĳ��Ĵ��������������������
ƽ̨��������հ�ճ��������������ɽ�Ʒǳ�����������һ��������
���������°���Ʈ�����治֪���ںξ���
LONG
        );
        set("outdoors", "zhongnan");
        set("exits", ([
                "north" : __DIR__"shijie9",
        ]));
        set("objects",([
                __DIR__"npc/youke" : 1,
                __DIR__"npc/xiangke" : 1,
        ]));
	set("coor/x", -3150);
	set("coor/y", 80);
	set("coor/z", 180);
	setup();
        replace_program(ROOM);
}