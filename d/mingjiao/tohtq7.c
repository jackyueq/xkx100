//TOHTQ7.C

inherit ROOM;

void create()
{
	set("short", "ɽ��");
	set("long", @LONG
ɽ�����ƺ���ɲ⣬�����ϵ��ż�յ�������յö���һ�ɹ�����
������Ȼ�е�ʮ�ֳ�ʪ���ɶ��ڸ����ʵ������ƽ����
LONG );
	set("exits", ([
		"north"  :__DIR__"htqmen",
		"south"  :__DIR__"tohtq6",
	]));
	set("no_clean_up", 0);
	set("coor/x", -52030);
	set("coor/y", 920);
	set("coor/z", 40);
	setup();
	replace_program(ROOM);
}