//  Room:  /d/luoyang/westroad.c

inherit  ROOM;

void  create  ()
{
	set("short",  "�ʶ���");
	set("long",  @LONG
�ഫ����ʱ���������ڴ����������ǣ��ʶ��ؼ��Ρ����Ұ�������
Ȼ���̲���������ǽ�����������ʪ�����ʯ·��Ȼ�Ǹո��¹��꣬��
Ϊ�������˹��࣬·�������Щ�ӿӰ�����һ����������ױ�������
������������֮����������Ǻų����ݵ�һ�Ľ������ˣ�������һ��
ר���������ʵĵ��̡�
LONG);
	set("exits",  ([  /*  sizeof()  ==  2  */
		"west"  :  __DIR__"westgate",
		"east"  :  __DIR__"center",
		"south" :  __DIR__"dianpu",
		"north" :  __DIR__"wanggate",
	]));
	set("objects",  ([  /*  sizeof()  ==  2  */
		__DIR__"npc/wangbofen" : 1,
	]));
	set("outdoors", "luoyang");
	set("coor/x", -600);
	set("coor/y", -10);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
