// /kaifeng/tangjian.c
// Last modified by winder 2003.10.20

inherit ROOM;

void create()
{
	set("short", "�ü�");
	set("long", @LONG
һ���ķ����ü䣬���еĹ����󻹰������ȱ�ķ�������ȱ�˰�
���Դ������ϰ���֩������ס�ˣ�Ҳ������ԭ����ģ����һ�ߵ�����
�Դ��˸����̣���ǽ���ż���ˮ�ޡ�
LONG);
	set("objects", ([
		__DIR__"npc/oldseng" : 1,
	]));
	set("exits", ([
		"west" : __DIR__"kongdi",
	]));

	setup();
	replace_program(ROOM);
}
