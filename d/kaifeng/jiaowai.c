// /kaifeng/jiaowai.c
// Last modified by winder 2003.10.20

inherit ROOM;

void create ()
{
	set ("short","����");
	set ("long", @LONG
�˴��ǿ��ⱱ���������뿪��ܽ����ΰ�����ȶ����ɴ�ȥ��ɽ��
��Ŀ������ﲻ����һ��̫ƽ����
LONG);
	set("outdoors", "kaifeng");
	set("exits", ([
		"south" : __DIR__"xuandemen",
		"westup" : __DIR__"shanlu1",
	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
