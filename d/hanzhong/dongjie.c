// dongjie.c ����
// Winder Oct.10 1998

inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
�����Ǻ�����Ķ��֣������߾��Ǻ��ж����ˡ��������Ǹ�С
���򣬲��㷱�������ϵ�����Ҳ��ϡ�١�������һ�ҿ�ջ����ջ��
�ڹ��Ű븱�������翴�졯�Ķ����������Ѿ���˺���ˡ�������һ
����լԺ���������ϲ���ͭ���������������ߣ����Ǻ��������
���ˡ�
LONG
        );
        set("outdoors", "hanzhong");
        set("exits", ([
                "east" : __DIR__"dongmen",
                "west" : __DIR__"zhongxin",
                "north" : __DIR__"kedian1",
                "south" : __DIR__"fu-damen",
        ]));
        set("objects", ([
                __DIR__"npc/seller" : 1,
        ]));
	set("coor/x", -3130);
	set("coor/y", -10);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}