//  Room:  /d/luoyang/lvzhuxiaoyuan.c

inherit  ROOM;

void  create  ()
{
	set("short",  "����СԺ");
	set("long",  @LONG
����һ�������ڱ��µ�����СԺ��Ժ���������С�ᣬ���������
���Դ����Ӽܳɡ����ϰ�����������������һ�������õ������ӡ�һ��
��������Ժ�������������������Ǹо������߽����ˣ�������ͷҲû��
̧һ̧��
LONG);
	set("exits",  ([  /*  sizeof()  ==  2  */
		"south"      :  __DIR__"lvzhulin",
		"northwest"  :  __DIR__"zuoshe1",
		"northeast"  :  __DIR__"youshe1",
	]));
	set("objects",  ([
		CLASS_D("heimuya")+"/lvzhuweng" : 1,
		__DIR__"obj/zhudao" : 1,
	]));
	set("outdoors", "luoyang");
	set("coor/x", -380);
	set("coor/y", 30);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}