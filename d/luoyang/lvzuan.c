// Room: /d/luoyang/lvzuan.c
// Last modified by winder 2002.11.11

inherit  ROOM;

void  create  ()
{
	set("short",  "������");
	set("long",  @LONG
�������ֽ����������������£��������֣�����Ϊ������ˮ����
��ԫ�̻���������С�����磬�������������������ɾ��������ֳ�Ϊ
���֣�����������Ъ��֮�������Ϊ���̳����������е�����ȫ���ɣ�
�������ȫ���ɡ����桱֮һ������������ʩ������δ�䣬�������
ģ��С�����Գơ������֡�����ơ����������� 
LONG);
	set("exits",  ([  /*  sizeof()  ==  2  */
		"southwest" : __DIR__"mangshan",
	]));
	set("outdoors", "luoyang");
	set("no_clean_up", 0);
	set("coor/x", -490);
	set("coor/y", 60);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}
