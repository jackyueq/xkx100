// Room: /d/wuxi/westroad2.c
// Winder 2000/02/22 

inherit ROOM;

void create()
{
	set("short", "���½�");
	set("long", @LONG
���½��ϵ�����Ȼ��ò����ˣ�����ȴ���ɾ������ࡣ����������
ߺ���������������һƬ���㿴��������Ϣ����Ⱥ�������쳣�˷ܺ͸�
�ˣ��ֱߵ�С��ߺ����С����ͷ�ͼ�����⽣�����ʳ���󿪡��ϱߵĶ�
Ȫ���ԭ�����ڻ�ɽ�µ������Ķ�Ȫ�Աߣ�����Ϊ�����⻹�ǰᵽ����
�������ˣ���ÿ�춼������ר��ȥ��Ȫ��ˮ������Ȫˮ���ġ�·����
����������������õĿ�ջ�������Ķ����������ϵر����ˡ�
LONG );
	set("outdoors", "wuxi");
	set("exits", ([
		"north" : __DIR__"kedian",
		"south" : __DIR__"chaguan",
		"west"  : __DIR__"westgate",
		"east"  : __DIR__"westroad1",
	]));
	set("objects", ([
		__DIR__"npc/wulai" : 1,
	]));
	set("coor/x", 350);
	set("coor/y", -800);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}