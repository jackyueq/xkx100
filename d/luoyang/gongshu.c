// Room: /d/luoyang/gongshu.c
// Last modified by winder 2002.11.11

inherit  ROOM;

void  create  ()
{
	set("short",  "���鴦");
	set("long",  @LONG
������ˮʱ��һ�������������������������Ϊ��������һ����
�����ߣ�����Ϊ�磬����Ϊ�㣬������롱����Ϊ���顣������������
�ƶ�����������֮���´󷨡���������Ӱ�������ˮ���ԣ��С������
�����ű���ͨ����˵Ϊ���ꡰ��깱�顱֮������ͼ���������֮����
����϶��������˺�һ˼��֮����ͼʽ����ӳ��������ѧ˼��֮���衣 
LONG);
	set("exits",  ([  /*  sizeof()  ==  2  */
		"west" : __DIR__"dukou1",
	]));
	set("outdoors", "luoyang");
	set("no_clean_up", 0);
	set("coor/x", -470);
	set("coor/y", -40);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
