// Room: /yangzhou/shiliji2.c
// Last Modified by Winder on Jul. 20 2000

inherit ROOM;

void create()
{
	set("short","ʮ�ﳤ��");
	set("long",@LONG
ʮ�ﳤ�����ǳ���ķ����ضΣ�һ�����ϣ�һ�ɵƺ���̣���Ϊ��
�֡�Ц�������������������������һƬ��������Ķ��䣬�㲻����Գ
��������ʹ�ͣ������һ�����ϱ���һ�����ֵĹ㳡��������һ�ҵ�
�̣�ǽ��д��һ�����ġ������֣���ϸ��������������ѹ�͵��ּۻ�
�۵���������������һƬ�����������š�һ��һʮ������Ǯ����ԭ����
�Ƿ�Բǧ��֮������һ�Ҷĳ���
LONG );
	set("outdoors", "yangzhouw");

	set("exits", ([
		"west"  : __DIR__"dangpu",
		"east"  : __DIR__"duchang",
		"south" : __DIR__"shilijie3",
		"north" : __DIR__"shilijie1",
	]));
	set("objects", ([
		CLASS_D("heimuya")+"/bao" : 1,
	]));
	set("coor/x", 10);
	set("coor/y", 10);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}