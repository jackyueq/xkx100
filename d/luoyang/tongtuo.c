// Room: /d/luoyang/tongtuo.c
// Last modified by winder 2002.11.11

inherit  ROOM;

void  create()
{
	set("short",  "ͭ��ĺ��");
	set("long",  @LONG
��ͭ��ĺ�ꡱ�������˴󾰵����һ�����Ƕ��������ͨ��塢
�ơ���ʱ�С�ͭ��İ������λ�����ƳǵĳǶ����硣ÿ��ĺɫãã����
�Ҵ������������������������꣬�׷��������������޲����ڵġ�
ͭ��ĺ�ꡱ��������
LONG);
	set("exits",  ([  /*  sizeof()  ==  2  */
		"west"  : __DIR__"xiaoxiang",
		"north" : __DIR__"jingu",
	]));
	set("outdoors", "luoyang");
	set("no_clean_up", 0);
	set("coor/x", -370);
	set("coor/y", 10);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
