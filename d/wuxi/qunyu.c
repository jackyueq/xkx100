// Room: /d/wuxi/qunyu.c
// Winder 2000/02/22 

inherit ROOM;

void create()
{
	set("short", "Ⱥ��Ժ");
	set("long", @LONG
��һ�߽�����һ�۾Ϳ���������ǽ�Ϲ���һ��������ͼ(tu)��һ��
�Ӿ�����������ʲô�ط������ڵ����ŵƽ�ʣ������˱ǡ���������
����������Ů�˷�վ���Զ��㷢����Ц������������¡�ǰǰ����к�
�ſ��ˡ�
LONG );
	set("exits", ([
		"west" : __DIR__"southroad2",
	]));
	set("item_desc", ([
		"tu" : "",
	]));
	set("objects", ([
		__DIR__"npc/laobao" : 1,
	]));
	set("coor/x", 380);
	set("coor/y", -830);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}