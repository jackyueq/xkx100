//Room: qianfoan.c ǧ����
//Date: Oct. 2 1997 by That

inherit ROOM;

void create()
{
	set("short","ǧ����");
	set("long",@LONG
�˴��Ǻ鴻ƺǧ���֡�ɽ��Сƺ�ӣ�������͵��֣��廷�뻤���������
��ᰣ�Ϫ���ᶣ��ƺ�Ϲ�ľ���裬ͤͤ��ǣ�ɽ����͸������Ʈ�Σ���Ϊ�ľ�
�������˴��������������������������ɣ���ɽ��������Ϊ������ν��ɽ�б�
���꣬�մ�ʪ���¡����������Ϊ��۵ġ��鴻���꡹���˴��������ģ�����
���죬����������;�����ǡ���ʮ�ŵ��ա������¾�������ջ����������
LONG);
	set("outdoors", "emei");
	set("exits",([ /* sizeof() == 1 */
		"southwest" : __DIR__"jsjdg1",
		"enter"     : __DIR__"qfadadian",
		"north"     : __DIR__"heilong2",
	]));
	set("no_clean_up", 0);
	set("coor/x", -6130);
	set("coor/y", -1060);
	set("coor/z", 80);
	setup();
}

int valid_leave(object me, string dir)
{
	int c_exp,c_skill;

	if (dir == "southwest" && userp(me))
	{
		c_exp=me->query("combat_exp");
		c_skill=me->query_skill("dodge",1);
		if ( me->query("qi") < 10 ) me->unconcious();
		else
		{
			me->receive_damage("qi", 10);
			if (((c_skill*c_skill*c_skill/10)< c_exp) &&
				(c_skill < 101))
				me->improve_skill("dodge", (int)me->query_skill("dodge", 1));
			tell_object(me,"���ؾ�ʮ�ŵ�������������һ�󣬾��ú��ۡ�\n");
		}
	}
	return 1;
}

