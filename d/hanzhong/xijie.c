// xijie.c ����
// Winder Oct.10 1998

inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
�������������ƶ����յľ۾��������ֱ������������ֵ���Ҳ
�Ե��������ҵöࡣ��������һ�����ʧ�޵�С���Ѿ�ҡҡ��׹�ˡ�
������һ���Ͱ���é�ݣ������Ǻ��е����š�������ת������������
��������������ˡ�
LONG
        );
        set("outdoors", "hanzhong");
        set("exits", ([
                "east" : __DIR__"zhongxin",
                "north" : __DIR__"minju2",
                "south" : __DIR__"xiaomiao",
                "west" : __DIR__"ximen",
        ]));
        set("objects", ([
                __DIR__"npc/punk" : 1,
        ]));

	set("coor/x", -3160);
	set("coor/y", -10);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}