// /d/xiakedao/mtroad2.c  ����
// Modified by Zeratul Jan 11 2001

inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
������ï�ܵ�ɭ�֡����ܶ���������ĳ��ݣ�һ����ɭ�ֲ���
���ա�Զ����ʱ����Ұ�޵ĺ��У���ʵ�ڲ��������������
LONG );
        set("outdoors", "motianya");
        set("exits", ([
            "east"  : __DIR__"mtroad1",
            "west"  : __FILE__,
            "south" : __FILE__,
            "north" : __DIR__"mtroad3",
        ]));
/*        set("objects", ([
            __DIR__"npc/zhangsan" : 1,
            __DIR__"npc/lisi" : 1,
        ]));*/
        setup();
        replace_program(ROOM);
}

