// Room: /yanziwu/ganquanjie.c
// Date: Jan.28 2000 by Winder

inherit ROOM;
void create()
{
	set("short","��Ȫ��");
	set("long",@LONG
��Ȫ��ԭ������������Ľֵ�֮һ������С�ػ��Ӷ�����������
�ǵ��������̼Ҷ��ȥ�³��ˣ���Ȫ�ֲ�������࣬Ҳ�ɾ���ࡣ����
��δ��֮ǰ����Ȫ���ϱ����澡�ǲ�����¥����ɫ���̡���ҷ׷��ֽ�
����������軨ľ��װ�ε��棬��ɽֵ�ӵ���������Ӷ����������
��Ա�ĳ����޷�ͨ�У������ؽ��³ǣ��ѵ���Ų���԰���������������
�����ľ�¥����������������㴹�����Ρ�
LONG );
	set("outdoors", "yangzhouw");
	set("no_clean_up", 0);
	set("exits", ([
		"south" : __DIR__"kedian",
		"north" : __DIR__"zuixianlou",
		"east"  : __DIR__"ninghaiqiao",
		"west"  : __DIR__"shilijie4",
	]));
	set("objects", ([
		CLASS_D("baituo")+"/ouyangke" :1,
	]));
	set("coor/x", 20);
	set("coor/y", -10);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}