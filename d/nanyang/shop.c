// Room: /d/nanyang/shop.c
// Last Modified by winder on Nov. 20 2001

inherit ROOM;
void create()
{
	set("short","�̺�");
	set("long",@LONG
һ�䲻��ĵ��̣����ž���һ���ư�ľδͿ��Ĺ�̨����Ȼ���õ�
�ܸɾ��������Լ��Ƕ���֮���ˣ�ľ�ʶ�������ơ�����һ�����̣�һ
���������̨һ�������Щ���Σ���壬���������������ȣ�Ӧ�о��С�
ǽ�Ϲ��ż����ֻ���
LONG);
	set("exits",([
		"east"  : __DIR__"dajie1",
	]));
	set("objects",([
		__DIR__"npc/boss" : 1,
	]));
	set("coor/x", 0);
	set("coor/y", 490);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
