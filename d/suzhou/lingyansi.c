// Room: /d/suzhou/lingyansi.c
// Last Modified by winder on May. 15 2001
inherit ROOM;

void create()
{
	set("short", "������");
	set("long",@long
����ɽ�������������¡�������ԭϵ�������޹���ַ��Ϊ��������
�����֡�����̾����ڵ�����ʼ�����ϳ���ԭ������¡��ƴ��ĳ�����
�£��ŷ����ڡ�
long);
	set("objects",([
		__DIR__"npc/ke" : 2,
	]));
	set("exits",([
		"northdown" : __DIR__"shiyuan",
		"west"      : __DIR__"zhonglou",
		"east"      : __DIR__"lingyanta",
		"enter"     : __DIR__"dxbdian",
	]));
	set("outdoors","suzhou");
	set("coor/x", 900);
	set("coor/y", -1120);
	set("coor/z", 30);
	setup();
	replace_program(ROOM);
}
