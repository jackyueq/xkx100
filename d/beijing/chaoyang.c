inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
������ǳ����ţ���ǽ�Ͽ��š������š��������֡����ž��ڶ���
�ߣ����������������ǽ������ǵ�Ҫ�����̲�ʮ�����ܡ�һ�������Ĵ�
���������죬ͨ����������������֡�������Ҳ���Գ������ǣ�������
���ǽ��⣬������һ��Ƭ���֣�һ����Ҳ��������
LONG );
	set("outdoors", "beijing");
	set("exits", ([
		"west" : __DIR__"chaoyan1",
	]));
	set("objects", ([
		"/d/city/npc/wujiang" : 1,
		"/d/city/npc/bing" : 2,
	]));
	set("coor/x", -160);
	set("coor/y", 4060);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
