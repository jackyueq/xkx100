// /d/yixing/cldating.c
// Last Modified by winder on Jul. 12 2002

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
������һ����ɱ����֮�������ü�Ϊ�����������ʮ��֮�ڡ�ֻ
���������ϵ������λεľ������п���һ�Ż�Ƥ���Ρ���ʱ�а��ھ�
�����������Ϣ�����ص�ͷ�߹�����
LONG );

	set("exits", ([
		"out"   : __DIR__"cldamen",
		"north" : __DIR__"clzoulang1",
	]));
	set("objects",([
		__DIR__"npc/cl_bei" : 1,
	]));
	setup();
	replace_program(ROOM);
}
