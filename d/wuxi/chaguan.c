// Room: /d/wuxi/chaguan.c
// Winder 2000/02/22 

inherit ROOM;

void create()
{
	set("short", "��Ȫ����");
	set("long", @LONG
һ������������һ���������ã��ϻ�һ����ƮƮ֮�����ˣ����˲�
ʥ½��֮����ʾ����������Ҷ֮���ڡ�����Ʈ��һ��������Ƣ�Ĳ��㡣
���������˿��ˣ������̸Ц����ͷ�Ӷ�����Ҫ����������ƹʺ�ҥ
�ԣ������Ǹ������ڡ��Ӳ���Ĵ���(window)���Ը����ݺ�ĺ�ˮ��
LONG );
	set("resource/water", 1);
	set("item_desc", ([
		"window" : 
"�Ӵ�����ȥ������ĺ�ˮ��������ʣ����漸��
Ů�����ںӱ��ϴ�·�����ʱ����������Ц֮����\n",
	]));
	set("exits", ([
		"north" : __DIR__"westroad2",
	]));
	set("objects", ([
		__DIR__"npc/chaboshi" : 1,
	]));
	set("coor/x", 350);
	set("coor/y", -810);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}