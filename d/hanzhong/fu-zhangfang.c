// fu-zhangfang �ʷ�
// Winder Oct.10 1998

inherit ROOM;

void create()
{
        set("short", "�ʷ�");
        set("long", @LONG
�����Ǻ�Ա��ҵ��ʷ���������ש�̵أ����Ŵ������һ����
�ӣ�һ���ܼ�����������С�۾���ס�ظ�����ת���������ڴ�ʲ
ô�����⡣
LONG
        );
        set("exits", ([
                "east" : __DIR__"fu-datang",
        ]));
        set("objects", ([
                __DIR__"npc/guanjia" : 1,
        ]));

	set("coor/x", -3140);
	set("coor/y", -40);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}