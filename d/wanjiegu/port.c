// Room: /t/wanjiegu/port.c

inherit ROOM;

void create()
{
        set("short", "���˶�");
        set("long", @LONG
�����ǰ�����׽���һ���ɿڣ�����������ڴ�����һ������
�ţ����Ǳ㲻���ٳ˴������ˡ��ű�ʯ����������ؿ�����������
�����˶ɡ���
LONG
        );
        set("outdoors", "wanjiegu");
        set("exits", ([ /* sizeof() == 2 */
            "west" : __DIR__"bridge",
            "east" : __DIR__"riverside3",
        ]));
        set("no_clean_up", 0);

        set("coor/x", -50050);
	set("coor/y", -19000);
	set("coor/z", -10);
	setup();
        replace_program(ROOM);
}
