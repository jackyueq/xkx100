// Last Modified by Sir on May. 22 2001
//Room: zhaitang.c ի��

inherit ROOM;
string* names = ({
	__DIR__"obj/mapo-doufu",
	__DIR__"obj/qingcai-fentiao",
	__DIR__"obj/culiu-baicai",
	__DIR__"obj/hongshao-qiezi",
});

void create()
{
	set("short","ի��");
	set("long",@LONG
������Ǻ�ɽ�����ֵ�ի�á�ի��������˳����Ĳ����ͳ��ʣ���
λСʦ̫������æµ�Ų�����ի���ϱ�ͨ����������ȡ�
LONG);
	set("exits",([ /* sizeof() == 1 */
		"south" : __DIR__"byawest",
	]));

	set("objects",([
		__DIR__"obj/qingshui-hulu" : 1,
		names[random(sizeof(names))]: 1,
		names[random(sizeof(names))]: 1,
		names[random(sizeof(names))]: 1,
	]));
//	set("no_clean_up", 0);
	set("coor/x", 30);
	set("coor/y", 3220);
	set("coor/z", 100);
	setup();
	replace_program(ROOM);
}
