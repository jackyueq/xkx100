// /d/yixing/clbajiaoting.c
// Last Modified by winder on Jul. 12 2002

inherit ROOM;

void create()
{
	set("short", "�˽�ͤ");
	set("long", @LONG
���ǻ�԰��һ��С�ɵ�ͤ�ӣ����ͻ�ʱ��Ϣ֮�á�ͤ��ʯ��ʯ��
��ȫ��ʯ���ϻ��ڷ��ż��̵��ġ�Ժ�л��ܰ��㸡����������ɽ����
���Ǳ��¡�
LONG );

	set("exits", ([
		"north" : __DIR__"clhuayuan",
		"west"  : __DIR__"clzoulang1",
	]));
	set("objects", ([
		__DIR__"npc/dingdang" : 1,
	]));
	set("outdoors", "yixing");
	setup();

	replace_program(ROOM);
}
