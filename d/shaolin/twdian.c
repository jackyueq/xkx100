// Room: /d/shaolin/twdian.c
// Date: YZC 96/01/19

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
�����������µ��е�����������������ƣ�᣽Ƕ��ˡ�
����ǰ��Ҫ��ʢ�öࡣ��ǰ�����Ÿ�����ӣ��ƺ���Զ��Ц
���е����շ��Ĵ������������ԣ���ִ�������˳��������
�����ϰ������ļ����ߣ����յ����վ������Τ�ԡ�ֻ������
����ף�����Ӣ�����������ݣ�˫�ֺ�ʮ������ƺ�����ϡ�
�������߸���һ��ƫ�
LONG );
	set("exits", ([
		"east" : __DIR__"twdian1",
		"west" : __DIR__"twdian2",
		"southdown" : __DIR__"taijie",
		"north" : __DIR__"guangchang2",
	]));
	set("objects",([
		CLASS_D("shaolin") + "/dao-guo" : 1,
		__DIR__"npc/xiang-ke" : 1,
	]));
//	set("no_clean_up", 0);
	set("coor/x", 0);
	set("coor/y", 820);
	set("coor/z", 110);
	setup();
	replace_program(ROOM);
}
