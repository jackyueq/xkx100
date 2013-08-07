// /d/shenlong/snakeroom.h
// Last Modified by winder on Jul. 12 2002

#include <ansi.h>

void init()
{
	object me = this_player();

	if( interactive(me) &&
		!objectp(present("xionghuang", me)) &&
		!objectp(present("snake", this_object())) &&
		random((int)me->query("combat_exp")) < 25000 )
	{
		remove_call_out("showup"); 
		call_out("showup", 1 + random(3));
	}
}

void showup()
{
	string snakefile, *snakegroup;
	object snake;

	snakegroup = query("snaketype");
	snakefile = snakegroup[random(sizeof(snakegroup))];
	snakefile = "/d/shenlong/npc/" + snakefile;

	snake = new(snakefile);

	message("vision", HIR"ͻȻһ��" + snake->query("name") + "�Ӳ�֪ʲô�ط����˳���������\n" NOR, this_object());
	snake->move(this_object());

	remove_call_out("disappear");
	call_out("disappear", 10 + random(10), snake);
}

void disappear(object snake)
{
	if( !objectp(snake) ) 
		return;

	if( !living(snake) || snake->is_fighting() || snake->is_busy() )
	{
		call_out("disappear", 10 + random(10), snake);
		return;
	}

	message_vision("ֻ��$N�ɿ�������ˡ�\n", snake);
	destruct(snake);
}

