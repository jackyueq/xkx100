// /kaifeng/jiaomen.c
// Last modified by winder 2003.10.20

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
��ǽ�Ǳ߿���һ��С�ţ������е�ɮ�˾ͽ����⡣��������ľ���ģ�
ԭ�ȵĺ����Ѿ�����ò���ˡ�һ�ߵ�Χǽ̣�˰�ߣ�Ѱ���˶�����
�������ϱ���Ƭ�˵أ����˽���������֡�
LONG
	);
	set("objects", ([
		__DIR__"npc/zhangsan" : 1,
	]));

	set("exits", ([
		"south" : __DIR__"caidi5",
		"north" : __DIR__"eroad0",
	]));
	set("outdoors", "xiangguosi");

	setup();
	replace_program(ROOM);
}
