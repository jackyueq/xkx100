// /kaifeng/fangzhang.c
// Last modified by winder 2003.10.20

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
�������ڵĳ��������˵�Ƚϼ򵥣����е�ǽ����д�Ÿ����ġ�
���֡���������һ�Ŵ�ϯ�ӣ�һ�Ű����ͷ���ϯ���м䡣����������
���档�ڿ�����ĵط����и����ţ������Ǹ�Сľ�㣬��˵���ɴ�ʦÿ
��ֻ�����Ƭ�̾;������档
LONG);
	set("exits", ([
		"south" : __DIR__"xiaoyuan",
	]));
	set("objects", ([
		__DIR__"npc/zhiqing" : 1,
	]));

	setup();
	replace_program(ROOM);
}
