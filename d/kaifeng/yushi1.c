// /kaifeng/yushi1.c
// Last modified by winder 2003.10.20

inherit ROOM;

void create()
{
	set("short", "ԡ��");
	set("long", @LONG
ÿ������³����գ����ж�������ˮ��ϴ��Щ���񡣳�Ϊϴ����
ϴ��Ĳ�ˮ���˵�ͷ��������£�����������Ȼˮ���࣬����Ҷ���
������ˮ����Ȼ��ٹ����ǲ��ᵱ���Ǳ��������������ר�ŵ�Сԡ��
������ʹ�á�
LONG);
	set("objects", ([
		__DIR__"npc/zhangzao" : 1,
	]));
	set("exits", ([
		"east" : __DIR__"zhongyuan",
		"west" : __DIR__"yushi2",
	]));

	setup();
	replace_program(ROOM);
}
