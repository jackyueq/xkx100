// Room: /t/wanjiegu/tunnel2.c

inherit ROOM;

void create()
{
        set("short", "�ص�");
        set("long", @LONG
�ص�����ߺڰ����������ǣ�һ��ùζ�˱Ƕ������ص���ʯ̨
���쳣�ֲڣ�������ǽ�ϲ�ʱ����ˮ�ε������ϡ�
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
            "south" : __DIR__"tunnel1",
            "out" : __DIR__"grassland",
        ]));
        set("no_clean_up", 0);

	set("coor/x", -51100);
	set("coor/y", -18990);
	set("coor/z", -10);
	setup();
        replace_program(ROOM);
}