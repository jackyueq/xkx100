// ROOM xuanbing1.c
// Last Modified by winder on Aug. 25 2001

inherit ROOM;
void create()
{
	set("short", "�����Ŷ�");
	set("long", @LONG
�����������Ŷ������涴��֮�Ͻ�����ʯӢ����״�ᾧ�壬�Ե�ʮ
��Ư����ǰ��һ���޴��¯��ǰվ��һλ��������������¯������ʲô
���£��Ա߼������δ��������Ŵ�ͷ�ô���һ���ƺ���Ҳ�ղ����ʲ
ô�������Ա���ϸ�ķ��ż��Ѹոճ�¯�ı��������ֺ��˵�ɱ�����Ǵ�
��Щ������ɢ�������ġ�
LONG );
	set("exits", ([
		"out" : __DIR__"xuanbing",
	]));
	set("objects" , ([
		__DIR__"npc/ouyezi" : 1,
	]) );
	set("coor/x", -41200);
	set("coor/y", 8980);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
