// Room: /d/taishan/tianjie.c
// Last Modified by Winder on Aug. 25 2001

inherit ROOM;

void create()
{
	set("short", "���");
	set("long", @LONG
�˵��������Ŷ�������������ʮ��С���۶����С���·ƽ��������
�����������Ͻ��С���ַ���·����ΪǬ¡�й����ƴ���ѧ����Դ����
�鴦��ַ���������������߱��������壬������Χ��ɽ�����ϱ�ص���
���š�
LONG );
	set("exits", ([
		"south"    : __DIR__"xiangshan",
		"eastup"   : __DIR__"weiping",
		"eastdown" : __DIR__"lianhua",
		"westdown" : __DIR__"nantian",
		"northup"  : __DIR__"kongziya",
	]));
	set("objects",([
		__DIR__"npc/xiao-fan" : 2,
		__DIR__"npc/tiao-fu" : 1,
	]));
	set("outdoors", "taishan");
	set("coor/x", 370);
	set("coor/y", 770);
	set("coor/z", 210);
	setup();
	replace_program(ROOM);
}
