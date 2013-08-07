// Room:  /d/luoyang/mudan.c
// Last modified by winder 2002.11.11

inherit  ROOM;

void  create  ()
{
	set("short",  "ĵ��԰");
	set("long",  @LONG
�Թ�����������ī��ɧ���Ƽ�������С�ʫ����֮�ƣ�ĵ��������
�磬���С����������������δ�ʫ��ŷ�����ڡ�����ĵ���ǡ�һ����д
�������������������ˣ�ĵ����Ϊ�����档���˾伴�����������ĵ���
ʹĵ�������������ĵ����Ʒ�ַ��࣬��ɫ�������������¡����С�
����ĵ�������¡�֮������������������ÿ��ٰ�����ĵ�����ᣬ�˳�
ӿ����εΪ׳�ۡ���˵����ؤ���������ķ����ڴ�һЦ�����
LONG);
	set("exits",  ([  /*  sizeof()  ==  2  */
		"southwest" : __DIR__"road5",
	]));
	set("objects",  ([  /*  sizeof()  ==  2  */
		"/clone/flower/mudan/black1" : random(2),
		"/clone/flower/mudan/black2" : random(2),
		"/clone/flower/mudan/blue1" : random(2),
		"/clone/flower/mudan/blue2" : random(2),
		"/clone/flower/mudan/green1" : random(2),
		"/clone/flower/mudan/green2" : random(2),
		"/clone/flower/mudan/magenta1" : random(2),
		"/clone/flower/mudan/magenta2" : random(2),
		"/clone/flower/mudan/mudan1" : random(2),
		"/clone/flower/mudan/mudan2" : random(2),
		"/clone/flower/mudan/purple1" : random(2),
		"/clone/flower/mudan/purple2" : random(2),
		"/clone/flower/mudan/purple3" : random(2),
		"/clone/flower/mudan/red1" : random(2),
		"/clone/flower/mudan/red2" : random(2),
		"/clone/flower/mudan/red3" : random(2),
		"/clone/flower/mudan/red4" : random(2),
		"/clone/flower/mudan/white1" : random(2),
		"/clone/flower/mudan/white2" : random(2),
		"/clone/flower/mudan/white3" : random(2),
		"/clone/flower/mudan/white4" : random(2),
		"/clone/flower/mudan/yellow1" : random(2),
		"/clone/flower/mudan/yellow2" : random(2),
	]));
	set("outdoors", "luoyang");
	set("no_get_from", 1);
	set("no_clean_up", 0);
	set("coor/x", -490);
	set("coor/y", -10);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
