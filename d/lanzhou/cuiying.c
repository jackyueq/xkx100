//  Room:  /d/lanzhou/cuiying.c

inherit  ROOM;

void  create  ()
{
	set("short",  "��Ӣ��");
	set("long",  @LONG
�����ڴ���ϣ����ż�ʵ����ʯ����档ӭ��һ���Ʒ������顰��
Ӣ�š��������֣��鷨���ɷ��裬���Ϊ�������ᡣ�䶫������ᣬ��
����ȴ�����൱�����񾲣��ϱ߲�ʱ��������������
LONG);
	set("exits",  ([  /*  sizeof()  ==  2  */
		"north" : __DIR__"street3",
		"south" : __DIR__"zhigong",
		"east"  : __DIR__"square",
	]));
	set("outdoors", "lanzhou");
	set("no_clean_up", 0);
	set("coor/x", -9300);
	set("coor/y", 2690);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}