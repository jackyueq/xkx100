// Room: /d/nanyang/hanshui2.c
// Last Modified by winder on Nov. 20 2001

inherit RIVER;

void create()
{
	::create();
	set("short", "��ˮ����");
	set("long", @LONG
��ˮ����Ҳ���൱���֣��Ա����ɿ�������һ����ֱ�Ĺٵ�ֱͨ��
�����˵���紾�ӣ�·�Լ��������������������Ҷ���һ����ġ���
����ӭ��Ʈ�εΪ׳�ۡ�Ҳ�в���С����·��������ѱ棬ȴҲ��
��ʢ����ȴ��
LONG );

	set("exits", ([
		"north" : __DIR__"nanmen",
	]));
	set("outdoors", "nanyang");
	set("no_clean_up", 0);
	set("coor/x", 10);
	set("coor/y", 400);
	set("coor/z", 0);
	set("to",__DIR__"hanshui1");
	setup();
}
