// fu-cemen ���Ҳ���
// Winder Oct.10 1998

inherit ROOM;

void create()
{
        set("short", "���Ҳ���");
        set("long", @LONG
������һ��С�ţ������������½�����������޽��ġ�����
ȻС���������ε���ģ����������Ƕ��������ͭ�����������ǹ�
�����������űߣ�һ�������˽����͡����������ҷ͡������ž�
�Ǻ�������Ͻ��ˣ����ź��Ǹ��ҵ�СԺ��
LONG
        );
        set("exits", ([
                "northwest" : __DIR__"nanjie",
                "east" : __DIR__"fu-xiaoyuan",
        ]));
        set("objects", ([
                __DIR__"npc/wolfdog" : 2,
        ]));
	set("coor/x", -3140);
	set("coor/y", -30);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}