//  Room:  /d/luoyang/southroad.c

inherit  ROOM;

void  create  ()
{
	set("short",  "�崨��");
	set("long",  @LONG
ʪ�����ʯ·��Ȼ�Ǹո��¹��꣬��Ϊ�������˹��࣬·�������
Щ�ӿӰ�����һ����������ױ����������ֱ�����Ϊ�������ˮ����
����
���������������ǵ����ţ����������������Ĺ�¥������������һ��ר
���������ʵĵ��̣�������һ����ĵ�����ĵ��̡�
LONG);
	set("exits",  ([  /*  sizeof()  ==  2  */
		"east"      :  __DIR__"huadian",
		"west"      :  __DIR__"dianpu",
		"south"     :  __DIR__"southgate",
		"north"     :  __DIR__"center",
		"southwest" :  __DIR__"luoshenmiao",
	]));
	set("objects",  ([  /*  sizeof()  ==  2  */
		"/d/village/npc/girl" : 1,
	]));
	set("outdoors", "luoyang");
	set("no_clean_up", 0);
	set("coor/x", -500);
	set("coor/y", -20);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
