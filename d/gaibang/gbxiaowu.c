// Room: gbdixiaoshi.c
// by aji

inherit ROOM;
void create()
{
        set("short", "�ּ�С��");
        set("long", @LONG
���߽���һ��С�ݡ�����ǽ�ڶ�����������ɣ�������һ���޼ʵ�
���֡���������Ρ����̾�Ϊ���ơ���һ���˱Ƕ����Ĺ�����ζ��ȴ��
���������ŵ����ո���롣
LONG );
        set("exits", ([ /* sizeof() == 1 */
            "west" : __DIR__"gbandao"
        ]));
	set("objects", ([
		CLASS_D("gaibang") + "/hong" : 1,
		"/d/city/obj/zhubang": 1,
		"/d/city/obj/gourou": 1,
		"/d/city/obj/jiudai": 1,
		"/d/city/obj/jitui": 1
	]));

	set("coor/x", 71);
	set("coor/y", 61);
	set("coor/z", 0);
	setup();

        replace_program(ROOM);
}
